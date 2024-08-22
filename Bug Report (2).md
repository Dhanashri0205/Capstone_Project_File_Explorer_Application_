# Bug Tracker for Console-Based File Explorer

This bug tracker contains a list of identified issues in the Console-Based File Explorer project. Each bug is documented with a description, steps to reproduce, expected behavior, actual behavior, possible fixes, and status.

## Bugs

### 1. Incorrect Handling of Hidden Files in `listFiles` Method

- **Description:**
  The `listFiles` method does not include hidden files (files starting with a dot `.`) when listing files in the specified directory.

- **Steps to Reproduce:**
  1. Run the File Explorer.
  2. Choose the option to list files in a directory.
  3. Enter a directory path that contains hidden files.

- **Expected Behavior:**
  The method should list all files, including hidden files.

- **Actual Behavior:**
  Hidden files are not listed.

- **Possible Fix:**
  Modify the `listFiles` method to include hidden files by checking the `is_regular_file` and `is_hidden` attributes in the directory iterator.

- **Status:** Open

### 2. Unhandled Exception when Copying a Non-existent File

- **Description:**
  The `copyFile` method does not handle cases where the source file does not exist, leading to an application crash.

- **Steps to Reproduce:**
  1. Run the File Explorer.
  2. Choose the option to copy a file.
  3. Enter a non-existent source file path.

- **Expected Behavior:**
  The method should handle the error gracefully and log an appropriate message.

- **Actual Behavior:**
  The application crashes.

- **Possible Fix:**
  Add a check using `std::filesystem::exists(src)` to verify if the source file exists before attempting to copy it. Log an error message if the file does not exist.

- **Status:** Open

### 3. Incorrect Directory Navigation in `goUpOneDirectory` Method

- **Description:**
  The `goUpOneDirectory` method may cause the program to navigate incorrectly if the current directory is the root directory.

- **Steps to Reproduce:**
  1. Run the File Explorer.
  2. Choose the option to go up one directory level from the root directory (e.g., `/`).

- **Expected Behavior:**
  The method should prevent navigating up from the root directory and log an appropriate message.

- **Actual Behavior:**
  The method might attempt to change the directory to an invalid path, resulting in an error or crash.

- **Possible Fix:**
  Implement a check to determine if the current directory is the root directory before navigating up. If it is, log an appropriate message and prevent the directory change.

- **Status:** Open

### 4. Incorrect Permission Setting for Non-Integer Input

- **Description:**
  The `setPermissions` method does not validate whether the input permissions are integers, leading to undefined behavior.

- **Steps to Reproduce:**
  1. Run the File Explorer.
  2. Choose the option to set file permissions.
  3. Enter non-integer permissions (e.g., `abc`).

- **Expected Behavior:**
  The method should validate the input to ensure permissions are integers, and prompt the user to enter valid permissions if not.

- **Actual Behavior:**
  Undefined behavior occurs when non-integer input is provided.

- **Possible Fix:**
  Implement input validation to ensure that the permissions entered are integers. If invalid input is detected, prompt the user to enter valid permissions.

- **Status:** Open

### 5. Potential Crash on Invalid Directory Change

- **Description:**
  The `changeDirectory` method does not handle invalid directory paths properly, leading to a potential crash.

- **Steps to Reproduce:**
  1. Run the File Explorer.
  2. Choose the option to change the directory.
  3. Enter an invalid directory path.

- **Expected Behavior:**
  The method should check if the directory exists before attempting to change to it and log an error if the path is invalid.

- **Actual Behavior:**
  The application may crash when an invalid directory path is entered.

- **Possible Fix:**
  Add a check using `std::filesystem::exists(directory)` to ensure the directory exists before changing to it. Log an error message if the directory does not exist.

- **Status:** Open

## Instructions for Developers

1. **Review Bugs:** Go through each bug listed above and analyze the issue.
2. **Fix Bugs:** Implement the suggested fixes or an alternative solution.
3. **Test Thoroughly:** Ensure that the bug fixes are thoroughly tested.
4. **Update Status:** Once a bug is fixed, update its status from "Open" to "Fixed."
5. **Commit Changes:** Document the changes in the commit message, referencing the bug ID.

---

### Note:

Please keep this bug tracker up to date as you identify and fix issues. Regular updates and thorough testing are essential for maintaining the stability and functionality of the File Explorer project.
