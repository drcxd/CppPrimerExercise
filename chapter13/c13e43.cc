/* I think I prefer the for style without lambda for less typeing.
 */

void StrVec::free() {
    if (elements) {
        for_each(elements, first_free,
            [] (std::string *p) -> void { alloc.destroy(p); });
        alloc.deallocate(elements, cap - elements);
    }
}
