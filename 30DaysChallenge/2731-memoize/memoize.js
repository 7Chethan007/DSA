/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache = new Map();
    let callCount = 0;

    const memoized = function(...args) {
        const key = JSON.stringify(args); // safe unique key for arguments
        if (cache.has(key)) return cache.get(key);

        // call underlying function and cache the result
        callCount += 1;
        const result = fn.apply(this, args);
        cache.set(key, result);
        return result;
    };

    memoized.getCallCount = function() {
        return callCount;
    };

    return memoized;
}
