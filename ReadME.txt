/**

    Project: Neural Network
    Description: Implementation of constructer and tester of different neural networks on C++

*/

Hi everyone!

I am glad that you interested in this project!
 But, in my opinion, you should not use it at all. Because if you 
 realy want to lean some Neural Networks API, jsut use Python with Keras
 or any other existing API. They are simpler, faster and better that my
 solution.
 
The main goal of this project is to compare the different castom 
 networks by speed and accuracy. So, i need to know the complexity of 
 using algorithms exactly, therefore, i want to write them myself.



 ////////////////////////////
 //NAMING AND COMMIT RULES://
 ////////////////////////////

If you want to join me with developing, please, follow this rules:

    1. NEVER commit directly to master branch!!!!!!!!!!!!!
    2. To solve any issue you HAVE TO create new branch
    2.1 Any new branches name have to start with "issue-#NUMBER"
    2.2 To simplify the understanding of issue use some short description with
        minuses "-" instead of spaces " ".
    2.3 For ONE issue may be MORE THAN ONE branch

        EXAMPLE: "Branches for Issue #4 Implement Json Validator"
                branch: issue-4-validator-implementation
                branch: issue-4-schema-validation-implementation

    3. All commits MUST to have any description
    3.1 All commits HAVE TO start with "[issue-#NUMBER]"
    3.2 After this HAVE to be one of following symbols in round brackets
    3.2.1 (+) - adding a new code of files
    3.2.2 (-) - deleting not used code or files
    3.2.3 (*) - modifying existing code. May be used to commit the
        small changes like above together.
    3.2.4 (=) - trivial changes: typo or comments
    3.2.4 (!) - bug fixing. If bug fixing task takes more than one commit
        it is better to use some of symbols above.
    3.3 After have to be some short description of changing
    3.4 If you need to write a big description, then at first row write a short,
        then step one row and write as much as you need.

        EXAMPLE: "Commit for issue-000 Initialize Project"
            commit: [issue-000] (+) Adding the ReadME.txt
            commit: [issue-000] (+) Adding commit rules to ReadME.txt

    4. Before pull or push update git to 2.25 or above
    4.1 All new branches have to be started at master, so you need to
        create a local master first:

        $ git fetch origin
        $ git checkout -b master origin/master

    4.2 First of all, checkout to local master and rebase to current state

        $ git checkout master
        $ git pull --rebase=merges

    4.3 Create new branch following to the rules above

        $ git checkout -b issue-4-validator-implementation

    4.4 Do some changes and push branch and create pull request

        $ git push origin -u HEAD

    4.5 When code-review is done, update local repository and rebase to actual master

        $ git fetch origin
        $ git checkout -b issue-4-validator-implementation
        $ git rebase -r origin/master

    4.6 Resolve conflicts, and update local master

        $ git checkout master
        $ git pull --rebase=merges

    4.7 Merge your branch with master WITH NO fast forward and push

         $ git merge --no-ff issue-4-validator-implementation
         $ git push origin


Not sure, if anyone wants to work with me and how exactly work in github, so this rules may be modified.

