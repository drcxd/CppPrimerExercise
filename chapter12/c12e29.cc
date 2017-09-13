/* Using do-while and while make no difference in executing.
 * When talking about reading, I don't think they are different
 * significantly too.
 */

void runQueries(ifstream &infile) {
    TextQuery tq(infile);
    do {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") {
            break;
        }
        print(cout, tq.query(s)) << endl;
    } while (true);
}
