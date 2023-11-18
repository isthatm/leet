int TABLE_SIZE = 10; // must be larger than 3
template <typename K>
struct KeyHash {
    unsigned long operato   r()(const K& key) const
    {
        return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
    }
};