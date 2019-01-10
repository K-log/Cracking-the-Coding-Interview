import java.util.Arrays;

class IsPermutation {
    // 1.2 - Check if a string is a permutation of another.

    public static boolean testPermutation(String s1, String s2){

        char[] ss1 = s1.toCharArray();
        char[] ss2 = s2.toCharArray();
        Arrays.sort(ss1);
        Arrays.sort(ss2);

        return Arrays.equals(ss1, ss2);

    }
}
