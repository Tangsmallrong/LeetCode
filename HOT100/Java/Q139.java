package hot100;

import java.util.*;

/**
 * 单词拆分
 * 动态规划
 */
public class Q139 {
    public boolean wordBreak(String s, List<String> wordDict) {
        // 定义哈希表存储单词字典, 方便查找
        HashSet<String> set = new HashSet<>(wordDict);

        int n = s.length();
        // 定义状态数组, dp[i]表示字符串前i个字符是否能被字典中的单词拼接而成
        // 目标是求解 dp[s.length()], 即整个字符串s是否可以被字典中的单词拼接
        boolean[] dp = new boolean[n + 1];

        // 初始化
        Arrays.fill(dp, false);
        dp[0] = true;

        // 遍历
        // 外层循环从1遍历到s.length()判断前i个字符是否可以拼接
        for (int i = 1; i <= s.length(); i++) {
            // 内层循环从0到i判断子字符串s[j:i]是否在字典中
            for (int j = 0; j < i; j++) {
                String sub = s.substring(j, i);
                // 若s的前j个字符可以由字典中的单词组成并且从第j到i的子字符串在字典中
                if (dp[j] && set.contains(sub)) {
                    // dp[i]为true, 即s的前i个字符可以由字典中的单词组成
                    dp[i] = true;
                    break;   // 当前i可以被拼接, 不再继续检查j
                }
            }
        }

        return dp[n];
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s = input.nextLine();
        String values = input.nextLine();

        String[] split = values.split("\\s+");
        ArrayList<String> wordDict = new ArrayList<>(split.length);
        Collections.addAll(wordDict, split);

        Q139 solution = new Q139();
        boolean res = solution.wordBreak(s, wordDict);
        System.out.println(res);
    }
}
