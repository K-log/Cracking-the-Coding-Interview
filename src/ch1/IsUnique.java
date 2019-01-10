package ch1;

import java.util.HashSet;
import java.util.Set;

class IsUnique {
    // 1.1 - Determine if two strings are unique.

    public static boolean testUnique(String word){
        Set<Character> ret = new HashSet<Character>() {};
        for(Character c : word.toCharArray()) {
            if (!ret.add(c))
                return false;
        }
        return true;
    }
}
