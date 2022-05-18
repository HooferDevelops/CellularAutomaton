#include <iostream>
#include "automaton.h"

int main() {
    Automaton automaton(200, 100);
    
    automaton.updateSpriteSize();

    automaton.start();

    return 0;
}