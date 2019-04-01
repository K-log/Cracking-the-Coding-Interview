package ch1;

class Urlify {
    // 1.3 - Convert a string to a URL viable string.

    public static String makeUrl(String s){
        char[] ss = s.toCharArray();
        StringBuilder ret = new StringBuilder();

        for(Character val : ss){
            if((int)val == 32) {
                ret.append("%20");
            } else {
                ret.append(val);
            }
        }

        return ret.toString();
    }
}
