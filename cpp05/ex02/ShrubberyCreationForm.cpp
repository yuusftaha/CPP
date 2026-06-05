#include "ShrubberyCreationForm.hpp"

// Sabit değerler (İsim: ShrubberyCreationForm, Sign: 145, Exec: 137)
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
    if (this != &assign)
        this->target = assign.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->checkForm(executor); 
    
    // Dosya adını oluştur (örneğin: bahce_shrubbery)
    std::string filename = this->target + "_shrubbery";
    
    // Dosyayı yazma modunda aç (std::ofstream -> Output File Stream)
    std::ofstream outfile(filename.c_str());
    
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;
    
    outfile.close(); // İşimiz bitince dosyayı kapatmayı unutmuyoruz
}