alias g++='g++ -Wall -Wextra -Wshadow -D_GLIBCXX_DEBUG -ggdb3 -std=gnu++23 -fmax-errors=2 -fsanitize=address,undefined -I .'
xmodmap -e 'clear lock' -e 'keycode 66=less greater' #caps = <>
#mkdir bits && g++ /usr/include/x86_64-linux-gnu/c++/13/bits/stdc++.h -o bits/stdc++.h.gch
