package hot100;

import java.util.*;

/**
 * 字母异位词分组
 */
public class Q49 {
    public List<List<String>> groupAnagrams(String[] strs) {
        // 创建哈希表, 键用于存储排序后的字符串, 值存储符合分组条件的字符串数组
        HashMap<String, List<String>> map = new HashMap<>();

        // 遍历字符串数组
        for (String str : strs) {
            // 对字符串进行排序, 先转成字符数组, 再对数组排序
            char[] keyArr = str.toCharArray();
            Arrays.sort(keyArr);
            String sortedKey = new String(keyArr);

            // 将字母序相同的字符串对应到相同的键
            // 使用 computeIfAbsent 方法来简化代码
            // 如果键不存在, 创建一个新的 ArrayList 并将其作为值插入到哈希表中, 然后将 str 添加到这个 ArrayList 中
            map.computeIfAbsent(sortedKey, k -> new ArrayList<>()).add(str);
        }

        return new ArrayList<>(map.values());
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入字符串数组
        System.out.println("请输入字符串数组（以空格分隔，回车结束）: ");
        String input = scanner.nextLine();
        String[] strs = input.split(" ");

        Q49 q49 = new Q49();
        List<List<String>> result = q49.groupAnagrams(strs);

        // 输出结果
        System.out.println("字母异位词组合结果: ");
        for (List<String> group : result) {
            System.out.println(group);
        }

        scanner.close();
    }
}
