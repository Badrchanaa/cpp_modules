
class Contact
{
    public:
        Contact(void);
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickname(void);
        std::string getSecret(void);
        void        setFirstName(std::string first_name);
        void        setLastName(std::string last_name);
        void        setNickname(std::string nickname);
        void        setSecret(std::string secret);
        ~Contact();
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _secret;
}