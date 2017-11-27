/* Yes, as long as we explicitly sepcify the template argument type. */
max<int>(i, d); // the doulbe is converted to int
max<double>(i, d); // the int is converted to double
