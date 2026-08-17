import os

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
    "QuickSort - QuickSelect": ["Sort Colors"],
    "Binary Search": ["Find First and Last Position of Element in Sorted Array", "Search in Rotated Sorted Array", "Median of Two Sorted Arrays"],
    "Backtracking": ["Permutations", "Subsets"],
    "Tree Traversal - Level Order": ["Binary Tree Level Order Traversal", "Binary Tree Right Side View"],
    "Tree Traversal - Pre Order": ["Binary Tree Preorder Traversal", "Path Sum III", "Serialize and Deserialize Binary Tree"],
    "Tree Traversal - In Order": ["Binary Tree Inorder Traversal", "Validate Binary Search Tree", "Kth Smallest Element in a BST"],
    "Tree Traversal - Post-Order": ["Binary Tree Postorder Traversal", "Lowest Common Ancestor of a Binary Tree", "Binary Tree Maximum Path Sum"],
    "BST - Ordered Set": ["My Calendar I"],
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
    "0-1 Knapsack": ["Partition Equal Subset Sum"],
    "Unbounded Knapsack": ["Coin Change"],
    "Longest Increasing Subsequence (LIS)": ["Longest Increasing Subsequence"],
    "2D Grid DP": ["Minimum Path Sum", "Longest Increasing Path in a Matrix"],
    "String DP": ["Longest Common Subsequence", "Word Break"],
    "Maths - Geometry": ["Reverse Integer", "Max Points on a Line"]
}

# 建立難度對應字典
difficulty_map = {
    "Majority Element": "Easy", "Product of Array Except Self": "Medium", "First Missing Positive": "Hard",
    "Is Subsequence": "Easy", "Reverse Words in a String": "Medium",
    "Counting Bits": "Easy", "Single Number III": "Medium",
    "Group Anagrams": "Medium", "Longest Consecutive Sequence": "Medium",
    "Container With Most Water": "Medium", "3Sum": "Medium", "Trapping Rain Water": "Hard",
    "Subarray Sum Equals K": "Medium",
    "Find All Anagrams in a String": "Medium", "Permutation in String": "Medium",
    "Longest Substring Without Repeating Characters": "Medium", "Minimum Window Substring": "Hard",
    "Maximum Subarray": "Medium",
    "Spiral Matrix": "Medium", "Rotate Image": "Medium",
    "Remove Nth Node From End of List": "Medium", "Swap Nodes in Pairs": "Medium", "Add Two Numbers": "Medium",
    "Reverse Nodes in k-Group": "Hard",
    "Linked List Cycle II": "Medium",
    "Valid Parentheses": "Easy", "Min Stack": "Medium",
    "Largest Rectangle in Histogram": "Hard",
    "Sliding Window Maximum": "Hard",
    "Sort Colors": "Medium",
    "Find First and Last Position of Element in Sorted Array": "Medium", "Search in Rotated Sorted Array": "Medium", "Median of Two Sorted Arrays": "Hard",
    "Permutations": "Medium", "Subsets": "Medium",
    "Binary Tree Level Order Traversal": "Medium", "Binary Tree Right Side View": "Medium",
    "Binary Tree Preorder Traversal": "Easy", "Path Sum III": "Medium", "Serialize and Deserialize Binary Tree": "Hard",
    "Binary Tree Inorder Traversal": "Easy", "Validate Binary Search Tree": "Medium", "Kth Smallest Element in a BST": "Medium",
    "Binary Tree Postorder Traversal": "Easy", "Lowest Common Ancestor of a Binary Tree": "Medium", "Binary Tree Maximum Path Sum": "Hard",
    "My Calendar I": "Medium",
    "Implement Trie (Prefix Tree)": "Medium", "Word Search II": "Hard",
    "Find Median from Data Stream": "Hard",
    "Top K Frequent Elements": "Medium",
    "Merge Intervals": "Medium", "Non-overlapping Intervals": "Medium",
    "Merge k Sorted Lists": "Hard",
    "LRU Cache": "Medium",
    "Jump Game II": "Medium",
    "Number of Islands": "Medium", "Clone Graph": "Medium", "Is Graph Bipartite": "Medium",
    "Rotting Oranges": "Medium", "Word Ladder": "Hard",
    "Course Schedule II": "Medium",
    "Number of Provinces": "Medium",
    "Min Cost to Connect All Points": "Medium",
    "Cheapest Flights Within K Stops": "Medium",
    "House Robber II": "Medium",
    "Partition Equal Subset Sum": "Medium",
    "Coin Change": "Medium",
    "Longest Increasing Subsequence": "Medium",
    "Minimum Path Sum": "Medium", "Longest Increasing Path in a Matrix": "Hard",
    "Longest Common Subsequence": "Medium", "Word Break": "Medium",
    "Reverse Integer": "Medium", "Max Points on a Line": "Hard"
}

def get_progress_bar(solved, total, length=10):
    """回傳文字版進度條"""
    if total == 0:
        return "`[" + "░" * length + "]`"
    ratio = solved / total
    filled = int(round(ratio * length))
    return "`[" + "█" * filled + "░" * (length - filled) + "]`"

def check_file_metadata(filepath):
    """打開檔案讀取前 30 行，判斷 Status 並擷取 Notes 與 Wrong Testcases"""
    status = "SOLVED" # 預設狀態
    notes = []
    wrong_cases = []
    
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            for _ in range(30): # 讀取前30行
                line = f.readline()
                if not line:
                    break
                
                stripped_line = line.strip()
                upper_line = stripped_line.upper()
                
                # 1. 判斷 Status
                if "STATUS: ACTIVE" in upper_line or "STATUS: TODAY" in upper_line:
                    status = "ACTIVE"
                elif "STATUS: REVIEW" in upper_line or "STATUS: AGAIN" in upper_line:
                    status = "REVIEW"
                elif "STATUS: STUCK" in upper_line or "STATUS: FAILED" in upper_line:
                    status = "STUCK"
                
                # 2. 擷取 Notes
                if "NOTE" in upper_line:
                    parts = stripped_line.split(":", 1)
                    if len(parts) > 1:
                        note_content = parts[1].strip()
                        if note_content:
                            notes.append(note_content)
                            
                # 3. 擷取錯誤測資 (Wrong Testcases / Fails)
                if "BUG" in upper_line:
                    parts = stripped_line.split(":", 1)
                    if len(parts) > 1:
                        wrong_content = parts[1].strip()
                        if wrong_content:
                            wrong_cases.append(wrong_content)
                            
        return status, notes, wrong_cases
    except Exception:
        return "SOLVED", [], []

def generate_markdown_report():
    base_dir = os.getcwd()
    
    # 統計全域進度與難度進度
    total_problems = 0
    total_solved_or_attempted = 0
    
    difficulty_stats = {
        "Easy": {"total": 0, "solved": 0},
        "Medium": {"total": 0, "solved": 0},
        "Hard": {"total": 0, "solved": 0}
    }
    
    md_lines = []
    
    # --- Title & Header ---
    md_lines.append("# 🚀 LeetCode 75 Mastery Tracker\n")
    
    # --- Status Legend Table ---
    md_lines.append("### 📋 Status Legend & Notes Guide")
    md_lines.append("| Status | Tag (in .cpp) | Description |")
    md_lines.append("| :--- | :--- | :--- |")
    md_lines.append("| ✅ **Solved** | *(None)* | Perfectly solved. Default state. |")
    md_lines.append("| 🎯 **Active** | `// Status: ACTIVE` | Planning to solve today or currently working on it. |")
    md_lines.append("| 🔄 **Review** | `// Status: REVIEW` | Solved but need practice. |")
    md_lines.append("| 🛑 **Stuck**  | `// Status: STUCK` | Couldn't solve, needs deep study. |")
    md_lines.append("| ⬜ **Pending**| *(No File)* | Not started yet. |\n")
    
    md_lines.append("> 💡 **How to add notes & errors**:\n> - Add `// Note: Your text` to save takeaways.\n> - Add `// Wrong: [1,2,3]` or `// Fails: ...` to record tricky testcases.\n")
    md_lines.append("---\n")
    
    # 預留全域進度條區塊位置
    global_progress_index = len(md_lines)
    md_lines.append("") 
    md_lines.append("---\n")
    
    # --- Topics ---
    for folder_name, problems in topics.items():
        safe_folder_name = folder_name.replace("/", "-").replace("\\", "-")
        topic_total = len(problems)
        topic_progress = 0
        topic_table_lines = []
        
        # 建立該主題的 Table Header (新增 Difficulty 與 Wrong Testcases 欄位)
        topic_table_lines.append("| Status | Difficulty | Problem | Notes | BUG |")
        topic_table_lines.append("| :--- | :--- | :--- | :--- | :--- |")
        
        for problem in problems:
            total_problems += 1
            diff = difficulty_map.get(problem, "Unknown")
            
            # 統計難度總數
            if diff in difficulty_stats:
                difficulty_stats[diff]["total"] += 1
                
            file_name = f"{problem}.cpp"
            folder_path = os.path.join(base_dir, safe_folder_name, file_name)
            root_path = os.path.join(base_dir, file_name)
            actual_path = folder_path if os.path.exists(folder_path) else (root_path if os.path.exists(root_path) else None)
            
            # 難度標籤色彩格式化
            diff_badge = f"🟢 {diff}" if diff == "Easy" else (f"🟡 {diff}" if diff == "Medium" else f"🔴 {diff}")
            
            if actual_path:
                topic_progress += 1
                
                if diff in difficulty_stats:
                    difficulty_stats[diff]["solved"] += 1
                
                # 取得狀態、筆記與錯誤測資
                status, notes, wrong_cases = check_file_metadata(actual_path)
                
                # 將筆記與錯誤測資串接成 HTML 換行格式
                notes_html = "<br>".join([f"💡 {n}" for n in notes]) if notes else "-"
                wrong_html = "<br>".join([f"`{w}`" for w in wrong_cases]) if wrong_cases else "-"
                
                # 填入表格
                if status == "ACTIVE":
                    topic_table_lines.append(f"| 🎯 **Active** | {diff_badge} | {problem} | {notes_html} | {wrong_html} |")
                elif status == "REVIEW":
                    topic_table_lines.append(f"| 🔄 **Review** | {diff_badge} | {problem} | {notes_html} | {wrong_html} |")
                elif status == "STUCK":
                    topic_table_lines.append(f"| 🛑 **Stuck** | {diff_badge} | {problem} | {notes_html} | {wrong_html} |")
                else:
                    total_solved_or_attempted += 1
                    topic_table_lines.append(f"| ✅ **Solved** | {diff_badge} | {problem} | {notes_html} | {wrong_html} |")
            else:
                topic_table_lines.append(f"| ⬜ Pending | {diff_badge} | {problem} | - | - |")
                
        progress_bar = get_progress_bar(topic_progress, topic_total)
        percentage = int((topic_progress / topic_total) * 100) if topic_total > 0 else 0
        
        md_lines.append(f"### 📁 {folder_name}")
        md_lines.append(f"> **Progress:** {progress_bar} **{percentage}%** ({topic_progress}/{topic_total})\n")
        md_lines.extend(topic_table_lines)
        md_lines.append("\n") 
        
    # --- Global Progress (處理字串組合與三個獨立進度條) ---
    global_progress_text = ["## 🏆 Global Progress"]
    
    # 總體進度
    g_bar = get_progress_bar(total_solved_or_attempted, total_problems, length=20)
    g_pct = int((total_solved_or_attempted / total_problems) * 100) if total_problems > 0 else 0
    global_progress_text.append(f"> **Overall:** {g_bar} **{g_pct}%** ({total_solved_or_attempted}/{total_problems})")
    global_progress_text.append(">") # 空白行區隔
    
    # 難度分級進度
    for diff in ["Easy", "Medium", "Hard"]:
        stats = difficulty_stats[diff]
        d_bar = get_progress_bar(stats["solved"], stats["total"], length=15)
        d_pct = int((stats["solved"] / stats["total"]) * 100) if stats["total"] > 0 else 0
        
        # 讓排版對齊 (補空白)
        padding = " " * (6 - len(diff))
        global_progress_text.append(f"> **{diff}:**{padding} {d_bar} **{d_pct}%** ({stats['solved']}/{stats['total']})")
        global_progress_text.append(">") # 空白行區隔

        
    md_lines[global_progress_index] = "\n".join(global_progress_text)
    
    output_filename = "progress_report.md"
    with open(output_filename, "w", encoding="utf-8") as file:
        file.write("\n".join(md_lines))
        
    print(f"✨ Report with Difficulty Bars & Testcase Tracking generated successfully! Saved to '{output_filename}'.")

if __name__ == "__main__":
    generate_markdown_report()