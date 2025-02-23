//
// Class header for NodeIterator
//

#ifndef NODEITERATOR_H
#define NODEITERATOR_H

#include "INode.h"
#include <coroutine>
#include <stack>

// Generator class for iteration
template <typename T>
struct Generator {
    struct promise_type {
        // Current yielded value
        T value;

        // Stores yielded value in value
        std::suspend_always yield_value(T v) {
            value = v;
            return {};
        }

        Generator get_return_object() {
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        // Pauses execution before the coroutine starts
        std::suspend_always initial_suspend() {
            return {};
        }

        // Suspend coroutine instead of exiting immediately
        std::suspend_always final_suspend() noexcept {
            return {};
        }

        void return_void () {};

        // Error handling
        void unhandled_exception() {
            std::terminate();
        }
    };


    using handle_type = std::coroutine_handle<promise_type>;
    handle_type handle;

    // Constructor
    explicit Generator(handle_type handle) : handle(handle) {}
    // Destructor
    ~Generator() { if (handle) handle.destroy(); }

    // Custom iterator
    struct iterator {
        handle_type handle;

        bool operator!=(std::default_sentinel_t) const {
            return !handle.done();
        }

        void operator++() {
            handle.resume();
        }

        T operator*() const {
            return handle.promise().value;
        }
    };

    iterator begin () {
        return {handle};
    }

    std::default_sentinel_t end () {
        return {};
    }

};


// Class for NodeIterator for coroutine traversal
class NodeIterator {
public:
    explicit NodeIterator(INode* root);
    // Generator method that takes root node as argument
    Generator<INode*> PostfixNodeStream();

private:
    INode* Root;
};

#endif //NODEITERATOR_H
