
class PhoneBook
{
    public:
        PhoneBook(void);
        void    addContact(Contact contact);
        void    searchContact(int id);
        ~PhoneBook();
    private:
        Contact contacts[8];
}