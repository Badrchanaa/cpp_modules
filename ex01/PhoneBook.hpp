
class PhoneBook
{
    public:
        PhoneBook(void);
        void    addContact(Contact contact);
        void    searchContact(int id);
        ~PhoneBook();
    private:
        Contact _contacts[8];
        int     _size;
}