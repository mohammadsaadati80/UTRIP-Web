#include "Exceptions.hpp"
using namespace std;

const char* NotFoundException::what() const throw()
{
	return NOT_FOUND_EXCEPTION_MESSAGE;
}

const char* BadRequestException::what() const throw()
{
	return BAD_REQUEST_EXCEPTION_MESSAGE;
}

const char* PermissionDeniedException::what() const throw()
{
	return PERMISSION_DENIED_EXCEPTION_MESSAGE;
}

const char* EmptyException::what() const throw()
{
	return EMPTY_EXCEPTION_MESSAGE;
}

const char* NotEnoughCreditException::what() const throw()
{
	return NOT_ENOUGH_CREDIT_EXCEPTION_MESSAGE;
}

const char* YouAreLoginException::what() const throw()
{
	return YOU_ARE_LOGIN_EXCEPTION_MESSAGE;
}

const char* UserNotFoundException::what() const throw()
{
	return USER_NOT_FOUND_EXCEPTION_MESSAGE;
}

const char* DuplicateUserException::what() const throw()
{
	return DUPLICATE_USER_EXCEPTION_MESSAGE;
}

const char* PasswordNotMatchException::what() const throw()
{
	return PASSWORD_NOT_MATCH_EXCEPTION_MESSAGE;
}