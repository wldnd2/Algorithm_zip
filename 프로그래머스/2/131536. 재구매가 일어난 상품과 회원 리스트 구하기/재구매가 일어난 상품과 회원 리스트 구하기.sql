# SELECT user_id, product_id
# FROM ONLINE_SALE
# WHERE user_id in (
#     SELECT user_id
#     FROM ONLINE_SALE
#     GROUP BY user_id
#     HAVING COUNT(product_id) >= 2
# )
# ORDER BY USER_ID, PRODUCT_ID DESC;

SELECT user_id, product_id
FROM ONLINE_SALE
GROUP BY user_id, product_id
HAVING COUNT(product_id) >= 2
ORDER BY USER_ID, PRODUCT_ID DESC;