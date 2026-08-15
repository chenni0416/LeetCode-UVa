import os
import shutil

# 75 題的主題與題目名稱字典
topics = {
    "Arrays": ["Majority Element", "Product of Array Except Self", "First Missing Positive"],
    "Strings": ["Is Subsequence", "Reverse Words in a String"],
    "Bit Manipulation": ["Counting Bits", "Single Number III"],
    "Hash Tables": ["Group Anagrams", "Longest Consecutive Sequence"],
    "Two Pointers": ["Container With Most Water", "3Sum", "Trapping Rain Water"],
    "Prefix Sum": ["Subarray Sum Equals K"],
    "Sliding Window - Fixed Size": ["Find All Anagrams in a String", "Permutation in String"],
    "Sliding Window - Dynamic Size": ["Longest Substring Without Repeating Characters", "Minimum Window Substring"],
    "Kadane's Algorithm": ["Maximum Subarray"],
    "Matrix (2D Array)": ["Spiral Matrix", "Rotate Image"],
    "Linked List": ["Remove Nth Node From End of List", "Swap Nodes in Pairs", "Add Two Numbers"],
    "LinkedList In-place Reversal": ["Reverse Nodes in k-Group"],
    "Fast and Slow Pointers": ["Linked List Cycle II"],
    "Stacks": ["Valid Parentheses", "Min Stack"],
    "Monotonic Stack": ["Largest Rectangle in Histogram"],
    "Monotonic Queue": ["Sliding Window Maximum"],
    "QuickSort - QuickSelect": ["Sort Colors"], # 名稱包含 / 已替換為 -
    "Binary Search": ["Find First and Last Position of Element in Sorted Array", "Search in Rotated Sorted Array", "Median of Two Sorted Arrays"],
    "Backtracking": ["Permutations", "Subsets"],
    "Tree Traversal - Level Order": ["Binary Tree Level Order Traversal", "Binary Tree Right Side View"],
    "Tree Traversal - Pre Order": ["Binary Tree Preorder Traversal", "Path Sum III", "Serialize and Deserialize Binary Tree"],
    "Tree Traversal - In Order": ["Binary Tree Inorder Traversal", "Validate Binary Search Tree", "Kth Smallest Element in a BST"],
    "Tree Traversal - Post-Order": ["Binary Tree Postorder Traversal", "Lowest Common Ancestor of a Binary Tree", "Binary Tree Maximum Path Sum"],
    "BST - Ordered Set": ["My Calendar I"], # 名稱包含 / 已替換為 -
    "Tries": ["Implement Trie (Prefix Tree)", "Word Search II"],
    "Two Heaps": ["Find Median from Data Stream"],
    "Top K Elements": ["Top K Frequent Elements"],
    "Intervals": ["Merge Intervals", "Non-overlapping Intervals"],
    "K-Way Merge": ["Merge k Sorted Lists"],
    "Data Structure Design": ["LRU Cache"],
    "Greedy": ["Jump Game II"],
    "Depth First Search (DFS)": ["Number of Islands", "Clone Graph", "Is Graph Bipartite"],
    "Breadth First Search (BFS)": ["Rotting Oranges", "Word Ladder"],
    "Topological Sort": ["Course Schedule II"],
    "Union Find": ["Number of Provinces"],
    "Minimum Spanning Tree": ["Min Cost to Connect All Points"],
    "Shortest Path": ["Cheapest Flights Within K Stops"],
    "1-D DP": ["House Robber II"],
    "0-1 Knapsack": ["Partition Equal Subset Sum"], # 名稱包含 / 已替換為 -
    "Unbounded Knapsack": ["Coin Change"],
    "Longest Increasing Subsequence (LIS)": ["Longest Increasing Subsequence"],
    "2D Grid DP": ["Minimum Path Sum", "Longest Increasing Path in a Matrix"],
    "String DP": ["Longest Common Subsequence", "Word Break"],
    "Maths - Geometry": ["Reverse Integer", "Max Points on a Line"] # 名稱包含 / 已替換為 -
}

def organize_cpp_files():
    # 取得目前 python 腳本所在的目錄路徑
    base_dir = os.getcwd()
    
    # 統計移動的檔案數量
    moved_count = 0

    for folder_name, problems in topics.items():
        # 處理資料夾名稱中作業系統不允許的特殊字元 (例如 /)
        safe_folder_name = folder_name.replace("/", "-").replace("\\", "-")
        folder_path = os.path.join(base_dir, safe_folder_name)

        for problem in problems:
            # 檔案名稱：確保包含副檔名 .cpp
            file_name = f"{problem}.cpp"
            source_file_path = os.path.join(base_dir, file_name)

            # 檢查該 .cpp 檔案是否存在於當前目錄
            if os.path.exists(source_file_path):
                # 如果主題資料夾還不存在，則建立它
                if not os.path.exists(folder_path):
                    os.makedirs(folder_path)
                    print(f"建立資料夾: {safe_folder_name}")

                # 移動檔案到主題資料夾內
                destination_path = os.path.join(folder_path, file_name)
                shutil.move(source_file_path, destination_path)
                print(f"成功移動檔案: {file_name} -> {safe_folder_name}/")
                moved_count += 1

    print(f"\n整理完畢！共移動了 {moved_count} 個 .cpp 檔案。")

if __name__ == "__main__":
    organize_cpp_files()