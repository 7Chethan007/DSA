SELECT *
FROM Users
WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$'
  AND BINARY RIGHT(mail, 13) = BINARY '@leetcode.com';
