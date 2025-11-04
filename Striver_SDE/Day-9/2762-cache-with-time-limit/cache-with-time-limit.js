var TimeLimitedCache = function() {
  // Map key -> { value, expiry: timestamp_ms, timerId }
  this.map = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
  const now = Date.now();
  let existedUnexpired = false;

  if (this.map.has(key)) {
    const entry = this.map.get(key);
    // If existing entry hasn't expired yet, mark existedUnexpired true
    if (entry.expiry > now) existedUnexpired = true;
    // clear previous timeout to avoid removing the new entry later
    clearTimeout(entry.timerId);
  }

  const expiry = now + duration;
  const timerId = setTimeout(() => {
    // delete when duration passes
    this.map.delete(key);
  }, duration);

  this.map.set(key, { value, expiry, timerId });
  return existedUnexpired;
};

/** 
 * @param {number} key
 * @return {number} value associated with key or -1 if expired/not found
 */
TimeLimitedCache.prototype.get = function(key) {
  const now = Date.now();
  const entry = this.map.get(key);
  if (!entry) return -1;
  if (entry.expiry <= now) {
    // expired: cleanup and return -1
    clearTimeout(entry.timerId);
    this.map.delete(key);
    return -1;
  }
  return entry.value;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
  const now = Date.now();
  // prune expired entries while counting
  for (const [k, entry] of this.map) {
    if (entry.expiry <= now) {
      clearTimeout(entry.timerId);
      this.map.delete(k);
    }
  }
  return this.map.size;
};

/**
 * Example:
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */
