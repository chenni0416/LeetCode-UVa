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
    "Depth First Search (DFS)": ["Number of Islands", "Clone Graph", "Is Graph Bipartite?"],
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

def get_progress_bar(solved, total, length=10):
    """回傳文字版進度條"""
    if total == 0:
        return "`[" + "░" * length + "]`"
    ratio = solved / total
    filled = int(round(ratio * length))
    return "`[" + "█" * filled + "░" * (length - filled) + "]`"

def check_file_metadata(filepath):
    """打開檔案讀取前 30 行，判斷 Status 與擷取 Notes"""
    status = "SOLVED" # 預設狀態
    notes = []
    
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
                # 只要開頭是 // Note: 或 // Notes: 就抓取冒號後面的文字
                # if upper_line.startswith("// NOTE:") or upper_line.startswith("// NOTES:"):
                if "NOTE" in upper_line:
                    # 用第一個冒號進行分割，保留原始大小寫與文字
                    parts = stripped_line.split(":", 1)
                    if len(parts) > 1:
                        note_content = parts[1].strip()
                        if note_content:
                            notes.append(note_content)
                            
        return status, notes
    except Exception:
        return "SOLVED", []

def generate_markdown_report():
    base_dir = os.getcwd()
    total_problems = 0
    total_solved_or_attempted = 0
    
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
    
    md_lines.append("> 💡 **How to add notes**: Add `// Note: Your text here` at the top of your `.cpp` files. Multiple lines are supported!\n")
    md_lines.append("---\n")
    
    global_progress_index = len(md_lines)
    md_lines.append("") 
    md_lines.append("---\n")
    
    # --- Topics ---
    for folder_name, problems in topics.items():
        safe_folder_name = folder_name.replace("/", "-").replace("\\", "-")
        topic_total = len(problems)
        topic_progress = 0
        topic_table_lines = []
        
        # 建立該主題的 Table Header (新增 Notes 欄位)
        topic_table_lines.append("| Status | Problem | Notes / Takeaways |")
        topic_table_lines.append("| :--- | :--- | :--- |")
        
        for problem in problems:
            total_problems += 1
            file_name = f"{problem}.cpp"
            
            folder_path = os.path.join(base_dir, safe_folder_name, file_name)
            root_path = os.path.join(base_dir, file_name)
            
            actual_path = folder_path if os.path.exists(folder_path) else (root_path if os.path.exists(root_path) else None)
            
            if actual_path:
                topic_progress += 1
                
                # 取得狀態與筆記
                status, notes = check_file_metadata(actual_path)
                
                # 將筆記串接成 HTML 換行格式 (如果沒有筆記則顯示短橫線)
                if notes:
                    notes_html = "<br>".join([f"💡 {note}" for note in notes])
                else:
                    notes_html = "-"
                
                # 填入表格
                if status == "ACTIVE":
                    topic_table_lines.append(f"| 🎯 **Active** | {problem} | {notes_html} |")
                elif status == "REVIEW":
                    topic_table_lines.append(f"| 🔄 **Review** | {problem} | {notes_html} |")
                elif status == "STUCK":
                    topic_table_lines.append(f"| 🛑 **Stuck** | {problem} | {notes_html} |")
                else:
                    total_solved_or_attempted += 1
                    topic_table_lines.append(f"| ✅ **Solved** | {problem} | {notes_html} |")
            else:
                topic_table_lines.append(f"| ⬜ Pending | {problem} | - |")
                
        progress_bar = get_progress_bar(topic_progress, topic_total)
        percentage = int((topic_progress / topic_total) * 100) if topic_total > 0 else 0
        
        md_lines.append(f"### 📁 {folder_name}")
        md_lines.append(f"> **Progress:** {progress_bar} **{percentage}%** ({topic_progress}/{topic_total})\n")
        md_lines.extend(topic_table_lines)
        md_lines.append("\n") 
        
    # --- Global Progress ---
    global_progress_bar = get_progress_bar(total_solved_or_attempted, total_problems, length=20)
    global_percentage = int((total_solved_or_attempted / total_problems) * 100) if total_problems > 0 else 0
    global_progress_text = f"## 🏆 Global Progress\n> **Overall:** {global_progress_bar} **{global_percentage}%** ({total_solved_or_attempted}/{total_problems})"
    
    md_lines[global_progress_index] = global_progress_text
    
    output_filename = "progress_report.md"
    with open(output_filename, "w", encoding="utf-8") as file:
        file.write("\n".join(md_lines))
        
    print(f"✨ Report with Notes generated successfully! Saved to '{output_filename}'.")

if __name__ == "__main__":
    generate_markdown_report()