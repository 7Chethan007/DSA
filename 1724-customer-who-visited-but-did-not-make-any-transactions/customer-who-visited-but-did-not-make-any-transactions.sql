# Write your MySQL query statement below
SELECT
  v.customer_id,
  COUNT(*) AS count_no_trans
FROM Visits v
LEFT JOIN Transactions t
  ON v.visit_id = t.visit_id
WHERE t.visit_id IS NULL   -- keep only visits that have no matching transaction
GROUP BY v.customer_id;