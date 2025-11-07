/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
  // For arrays: check length
  // For objects: check if there are any keys
  return Object.keys(obj).length === 0;
};
