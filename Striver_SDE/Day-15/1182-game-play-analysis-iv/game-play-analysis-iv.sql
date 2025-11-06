# Write your MySQL query statement below
SELECT
  ROUND(
    SUM(
      CASE
        WHEN EXISTS (
          SELECT 1
          FROM Activity a2
          WHERE a2.player_id = f.player_id
            AND a2.event_date = DATE_ADD(f.first_login, INTERVAL 1 DAY)
        ) THEN 1
        ELSE 0
      END
    ) / COUNT(*) , 2
  ) AS fraction
FROM (
  SELECT player_id, MIN(event_date) AS first_login
  FROM Activity
  GROUP BY player_id
) AS f;
