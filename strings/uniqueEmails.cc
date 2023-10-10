/*
Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, 
the email may contain one or more '.' or '+'.

For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded 
to the same address without dots in the local name. Note that this rule does not apply to domain names.

For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered. 
Note that this rule does not apply to domain names.

For example, "m.y+name@email.com" will be forwarded to "my@email.com".
It is possible to use both of these rules at the same time.

Given an array of strings emails where we send one email to each emails[i], return the number of different addresses that actually 
receive mails.
 

Example 1:

Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.
*/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string &email : emails) {
            int domainIndex = email.find('@'); // contains exactly one
            string local = email.substr(0, domainIndex);
            string domain = email.substr(domainIndex+1);

            // not empty
            if (local == "" || domain == "") continue;

            // local names do not start with '+' char
            if (local[0] == '+') continue;

            // domain names end with ".com" suffix
            if (domain.find(".com") == string::npos) continue;

            // periods in local name -- can have multiple
            while (local.find('.') != string::npos) {
                int periodIndex = local.find('.');
                local.erase(periodIndex, 1); // erase period
            }

            // + in local name
            if (local.find('+') != string::npos) {
                int plusIndex = local.find('+');
                local.erase(plusIndex);
            }

            string newEmail = local + "@" + domain;
            s.insert(newEmail);

        }

        return s.size();
    }
};
