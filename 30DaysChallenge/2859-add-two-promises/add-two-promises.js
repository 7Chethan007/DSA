/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
  // Wait for both promises to resolve
  const [val1, val2] = await Promise.all([promise1, promise2]);
  
  // Return their sum
  return val1 + val2;
};

/**
 * Example:
 * addTwoPromises(Promise.resolve(2), Promise.resolve(5))
 *   .then(console.log); // 7
 */
