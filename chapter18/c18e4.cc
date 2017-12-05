/* The sequnce of the classes using inheritance is reversed. The last
 * two catch will not be matched forever.
 */

try {
    //
} catch (overflow_error eobj) {
    //
} catch (const runtime_error &re) {
    // 
} catch (exception) {
    // 
}
