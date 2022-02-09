#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include <exception>

#define NOT_FOUND_EXCEPTION_MESSAGE "Not Found\n"
#define BAD_REQUEST_EXCEPTION_MESSAGE "Bad Request\n"
#define PERMISSION_DENIED_EXCEPTION_MESSAGE "Permission Denied\n"
#define EMPTY_EXCEPTION_MESSAGE "Empty\n"
#define NOT_ENOUGH_CREDIT_EXCEPTION_MESSAGE "Not Enough Credit\n"
#define YOU_ARE_LOGIN_EXCEPTION_MESSAGE "You Are Login\n"
#define USER_NOT_FOUND_EXCEPTION_MESSAGE "User Not Found\n"
#define DUPLICATE_USER_EXCEPTION_MESSAGE "Email or Username is Duplicate\n"
#define PASSWORD_NOT_MATCH_EXCEPTION_MESSAGE "Password Not Match\n"

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw();
};

class BadRequestException : public std::exception
{
public:
	const char* what() const throw();
};

class PermissionDeniedException : public std::exception
{
public:
	const char* what() const throw();
};

class EmptyException : public std::exception
{
public:
	const char* what() const throw();
};

class NotEnoughCreditException : public std::exception
{
public:
	const char* what() const throw();
};

class YouAreLoginException : public std::exception
{
public:
	const char* what() const throw();
};

class UserNotFoundException : public std::exception
{
public:
	const char* what() const throw();
};

class DuplicateUserException : public std::exception
{
public:
	const char* what() const throw();
};

class PasswordNotMatchException : public std::exception
{
public:
	const char* what() const throw();
};

#endif 