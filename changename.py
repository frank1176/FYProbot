import os

def rename_files(folder_path):
    # Get a list of all files in the folder
    files = os.listdir(folder_path)

    # Iterate over each file
    for i, filename in enumerate(files):
        # Construct the new file name
        new_filename = f"train1_{i}.jpg"

        # Get the full paths of the old and new file names
        old_filepath = os.path.join(folder_path, filename)
        new_filepath = os.path.join(folder_path, new_filename)

        # Rename the file
        os.rename(old_filepath, new_filepath)
        print(f"Renamed '{filename}' to '{new_filename}'")

# Provide the folder path
folder_path = 'C:/Users/user/Pictures/Camera Roll'

# Call the function to rename the files
rename_files(folder_path)
