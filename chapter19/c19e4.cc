try {
    C &c = dynamic_cast<C &>(*pa);
    // ...
} catch (std::bad_cast bc) {
    // ...
}
