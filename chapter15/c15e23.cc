int fcn() override;

bp1->fcn(); /* call fcn in Base */
bp2->fcn(); /* call fcn in D1 */
bp3->fcn(); /* call fcn in D2 */

p1->fcn(42); /* error: Base has no member fcn take an int argument */
p2->fcn(42); /* error: D1 has no member fcn take an int argument */
p3->fnc(42); /* call fcn that takes an int argument in D2 */
