# Write your MySQL query statement below

SELECT * FROM Cinema 
WHERE description !=  'boring'
group by id
having (id%2 != 0)

order by rating desc
