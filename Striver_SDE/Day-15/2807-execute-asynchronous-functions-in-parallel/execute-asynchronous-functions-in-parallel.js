/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
  return new Promise((resolve, reject) => {
    const n = functions.length;
    if (n === 0) return resolve([]);

    const results = new Array(n);
    let resolvedCount = 0;
    let rejected = false;

    for (let i = 0; i < n; i++) {
      let fn = functions[i];
      let p;
      try {
        p = fn(); // may throw synchronously
      } catch (err) {
        // synchronous throw -> reject immediately
        return reject(err);
      }

      // attach handlers directly to the returned promise
      p.then((val) => {
        if (rejected) return;
        results[i] = val;
        resolvedCount += 1;
        if (resolvedCount === n) resolve(results);
      }).catch((err) => {
        if (rejected) return;
        rejected = true;
        reject(err);
      });
    }
  });
};


/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */