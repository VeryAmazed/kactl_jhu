alias g++='g++ -Wall -Wextra -Wshadow -D_GLIBCXX_DEBUG -ggdb3 -std=gnu++20 -fmax-errors=2 -fsanitize=address,undefined -I.'
# mkdir bits && cd bits && g++ /usr/include/x86_64-linux-gnu/c++/13/bits/stdc++.h -o stdc++.h.gch
# test: g++ template.cpp -H