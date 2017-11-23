BinaryQuery a = Query("fiery") & Query("bird");
/* Illegal. BinaryQuery is an abstract class since it has a pure
 * virtual function eval inherited from Query_base. We can't construct
 * an abstract class directly 
 */
AndQuery b = Query("fiery") & Query("bird");
/* Illegal. operator& will return a query object. We can't convert a
 * query object to an AndQuery object.
 */
OrQuery c = Query("fiery") & Query("bird");
/* Illegal. Same as above. */
