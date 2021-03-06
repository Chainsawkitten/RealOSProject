#ifndef SHELL_HPP
#define SHELL_HPP

#include <string>
#include <vector>
#include "FileSystem.hpp"

/// %Shell the user can interact with the file system through.
class Shell {
public:
	/// Create new shell.
	/**
	 * @param user Username.
	 */
	Shell(const std::string &user);

	/// Read and parse a user command.
	/**
     * Type `help` for a list of available commands.
	 * @return Whether execution should continue
	 */
	bool getCommand();

private:
	FileSystem fileSystem;

	std::string user;
	std::string currentDir;
    
    /// Takes usercommand from input and returns number of commands, commands are stored in strArr[].
	/**
	 @param userCommand The command the user wants to execute.
	 @param strArr[] Array that stores commands.
	 @return the number of commands
	 */
	static int parseCommandString(const std::string &userCommand, std::string strArr[]);

	/// Find command index based on command name.
	/**
	 @param command Command string.
	 @return The index number of the command, -1 if command could not be found
	 */
	static int findCommand(std::string &command);

	/// Get the absolute path.
	/**
	 * Makes path absolute and handles ./ and ../
	 * @param path Relative or absolute path. Absolute path indicated by leading /.
	 * @return Absolute path
	 */
	std::string absolutePath(std::string path) const;

	/// Returns help-string.
	/**
	 @return A string with helpful information
	 */
	static std::string help();
    
    /// Split a string by a delimiter.
    /**
     * @param text The string to split.
     * @param delimiter The delimiter to split the string around.
     * @return The parts of the string as a vector
     */
    static std::vector<std::string> split(std::string text, char delimiter);
};
#endif // SHELL_HPP
