# surveyTaker
With survery taker you're allowed to do the following with little or no issue:
- Create and admin account - the admin code is embedded within my C++, it is "vaultBoy"
- Create a user account
- Create a survey (admin only)
- Take a survey (user only)
- view a survey (admin only)
- Log in and out of accounts wihtout program restart
- Error checking for invalid inputs so that it does not crash the program

When first opening there is no accounts or surveys created, you'll have to follow the prompts to create an admin account then create a survey. Once created you may log out to return to the main screen, create a user account, login and then follow the prompts to take a survey. To select a survey you will have to type it in exactly displayed and you will be able to take the survey. You may log out then log back in as the admin that created the survey(if you create a different admin account you will NOT be able to see another admins survey), then you may follow the prompt to see how the user responded to your survey. 

Known issues:
Global variables - bad in practice however this was a intro to programming class and that redundicy was not reviewed. I have yet to update this project to accurate follow OOP principles and to utilize data structures. 
