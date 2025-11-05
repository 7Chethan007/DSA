# Write your MySQL query statement below
SELECT
  ROUND(
    SUM(CASE WHEN d.customer_pref_delivery_date = d.order_date THEN 1 ELSE 0 END) 
    / COUNT(*) * 100,
    2
  ) AS immediate_percentage
FROM Delivery d
JOIN (
  SELECT customer_id, MIN(order_date) AS first_order_date
  FROM Delivery
  GROUP BY customer_id
) firsts
  ON d.customer_id = firsts.customer_id
 AND d.order_date = firsts.first_order_date;
