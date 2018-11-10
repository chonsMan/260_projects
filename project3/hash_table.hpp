#ifndef HASH_TABLE
#define HASH_TABLE
#include "list.hpp"
#include "victor.hpp"
#include "hasher.hpp"

template <typename Key, typename Value>
struct HashTable{ 
    // Constructor constructs a new list and pushes it onto victor.
    // Note that the storage vector is composed of a list, which contain 
    // name/value pairs per the Entry struct.
    HashTable() : storage{ Victor<List<Entry>> {NUM_BUCKETS} }{
        for (size_t _{0}; _ < NUM_BUCKETS; _++){
            storage.push(List<Entry>{}); 
        }
    }
    // Destructor
    ~HashTable() = default;

    void filter(std::function<bool(Value const &)> predicate) {
        for(size_t i{0}; i < NUM_BUCKETS; i++) { 
            storage[i].filter(
                [&](Entry const & entry){
                    return predicate(entry.value);
                }
            );
        }
    }


    void for_each(std::function<void (Value &)> funfaction) {
        // Adapter will call funfaction on the value
        // It will *capture* funfaction
        auto adapter = [&](Entry & entry) { funfaction(entry.value); };
        for(size_t i{0}; i < storage.get_size(); i++) {
            storage[i].for_each(adapter); // Return each linked list at each bucket; call for_each
        }
    }


    Value & operator[](Key const & index) {
        // Hash the key  and get a reference to the LL to search
        List<Entry> & list = storage[Hasher::crc32(index) % NUM_BUCKETS]; 
        // Find the entry with the given key; define function predicate as a lambda
        // [&] means taking index by reference
        Entry * entry = list.find(
            [&](Entry const & entry){
                return entry.key == index;
            }
        ); 
        // If it doesn't exist, create an entry
        if (entry == nullptr) {
            list.push_front(Entry{index, Value{}}); 
            entry = & list.front(); // Address of head data
        } 
        // Return a reference to the value in that entry
        return entry->value;
        // That is the entire thing    
    };

private:
    struct Entry{
        Key key;
        Value value;
    }; // Entry

    static size_t const NUM_BUCKETS {3};
    Victor<List<Entry>> storage;
}; // HashTable


#endif