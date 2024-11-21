#ifndef _JAM_EXCEPTIONS_H
#define _JAM_EXCEPTIONS_H

#include <stdexcept>
#include <string>

namespace Jam
{
	class FileNotFoundException : public std::runtime_error
	{
	public:
		explicit FileNotFoundException(const std::string& message ) : std::runtime_error( message ) {}
	};

	class NullChildElementException : public std::runtime_error
	{
	public:
		explicit NullChildElementException(const std::string& message ) : std::runtime_error( message ) {}
	};

	class TextureInitializationException : public std::runtime_error
	{
	public:
		explicit TextureInitializationException(const std::string& message ) : std::runtime_error( message ) {}
	};

	class WindowInitializationException : public std::runtime_error
	{
	public:
		explicit WindowInitializationException(const std::string& message ) : std::runtime_error( message ) {}
	};

	class SDLSubsystemException : public std::runtime_error
	{
	public:
		explicit SDLSubsystemException(const std::string& message ) : std::runtime_error( message ) {}
	};

	class SDLImageSubsystemException : public std::runtime_error
	{
	public:
		explicit SDLImageSubsystemException(const std::string& message ) : std::runtime_error( message ) {}
	};

}

#endif // _JAM_EXCEPTIONS_H