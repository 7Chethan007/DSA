class EventEmitter {
    constructor() {
        // Map eventName -> array of callbacks
        this.events = {};
    }
    
    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        if (!this.events[eventName]) {
            this.events[eventName] = [];
        }
        this.events[eventName].push(callback);

        return {
            unsubscribe: () => {
                const listeners = this.events[eventName];
                if (!listeners) return;

                const idx = listeners.indexOf(callback);
                if (idx !== -1) {
                    listeners.splice(idx, 1);
                }
                // implicitly returns undefined
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        const listeners = this.events[eventName];
        if (!listeners || listeners.length === 0) return [];

        const results = [];
        for (const cb of listeners) {
            results.push(cb(...args));
        }
        return results;
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe();       // undefined
 * emitter.emit('onClick'); // []
 */
