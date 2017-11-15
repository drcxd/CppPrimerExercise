Base *p = &d1; // legal

p = &d2; // illegal, since subobject part of Base in d2 is private so
         // can't be accessed through pointer to Base

p = &d3; // illegal, same as above

p = &dd1; // legal

p = &dd2; // illegal, same as above

p = &dd3; // illegal, same as above
