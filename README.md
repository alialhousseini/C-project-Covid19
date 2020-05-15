# C-project-Covid19

## Idea

Citizen Covid Detect and Track (CCDT) is a software that you were hired to design and implement for the ministry of health and ministry of interior. Needless to say, any work on the project (ideas, explanations, pieces of code, etc...) that is shared between different teams will be counted as plagiarism and severely dealt with.


## Content
Your program is meant to compare genetic patterns to identify whether a person’s blood sample contains the virus COVID-19 or not, then Identify other people who have been in the same region as your “patient 0” (first tested case, first name on the list), and finally test them and so on and so forth... Your program must read from a file the following:
1. Person’s first name.
2. Last name.
3. Phone number.
4. Genetic sequence (extracted from the blood sample).
5. Areas in the city that he/she has been to (this is identified by the cell towers that he connected from.

Compare the genetic sequence with the one of COVID -19. In order to identify if a person is infected or not. BEWARE, COVID is a sneaky virus that has been undergoing several mutations. This means that the genetic sequence can have up to 2 different, [Nucleotides](https://www.ncbi.nlm.nih.gov/Class/MLACourse/Original8Hour/Genetics/nucleotide.html) and it is still considered COVID-19.

Your program must output the list of all people infected, and those who were tested but were not infected, finally the list of people who were not tested because they were not in the same geographical location. To make it easy for the authorities, please have the lists sorted and output to a text file named: "output.txt".
