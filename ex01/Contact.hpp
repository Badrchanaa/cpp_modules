#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

# include <string>

class Contact
{
	public:
		Contact(void);
		Contact     &operator=(Contact const & ct);
		bool        promptFields(void);
		void        print(void) const;
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getSecret(void) const;
		void        setFirstName(std::string first_name);
		void        setLastName(std::string last_name);
		void        setNickname(std::string nickname);
		void        setPhoneNumber(std::string phone_number);
		void        setSecret(std::string secret);
		static bool	validPhoneNumber(std::string const &phoneNumber);
		~Contact();
	private:
		void    _promptField(std::string prompt_msg, std::string &field);
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _secret;
};

#endif