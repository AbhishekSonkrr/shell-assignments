import os

def search_substring_in_files(substring, file_list):
    total_count = 0
    file_counts = {}

    for file in file_list:
        try:
            with open(file, "r", encoding="utf-8", errors="ignore") as f:
                content = f.read()
                count = content.count(substring)
                file_counts[file] = count
                total_count += count
        except FileNotFoundError:
            print(f"File not found: {file}")
        except Exception as e:
            print(f"Error reading {file}: {e}")

    return total_count, file_counts


if __name__ == "__main__":
    # Example usage
    substring = input("Enter the substring to search: ")

    # You can manually list files or automatically get from a directory
    directory = "./"   # current directory
    file_list = [os.path.join(directory, f) for f in os.listdir(directory) if f.endswith(".txt")]

    total, counts = search_substring_in_files(substring, file_list)

    print("\nOccurrences per file:")
    for file, cnt in counts.items():
        print(f"{file}: {cnt}")

    print(f"\nTotal occurrences across all files: {total}")

