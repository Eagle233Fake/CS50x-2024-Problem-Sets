SELECT * FROM crime_scene_reports
WHERE street = 'Humphrey Street'
AND year = 2023 AND month = 7 AND day = 28;

SELECT * FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND day = 28
AND hour = 10 AND minute < 30 AND minute > 0;

SELECT * FROM people
WHERE license_plate = '13FNH73'
OR license_plate = '5P2BI95'
OR license_plate = '94KL13X'
OR license_plate = '6P58WS2';

SELECT * FROM bank_accounts
WHERE person_id = 221103
OR person_id = 243696
OR person_id = 686048
OR person_id = 745650;

SELECT account_number, atm_location, transaction_type, year, month, day, amount FROM atm_transactions
WHERE account_number = 49610011
OR account_number = 42445987
OR account_number = 56171033
AND year = 2023 AND month = 7 AND day >= 28 AND day <= 31;

SELECT * FROM atm_transactions WHERE account_number = 49610011
AND year = 2023;

SELECT * FROM phone_calls
WHERE caller = '(367) 555-5533' or receiver = '(367) 555-5533'
AND year = 2023;

SELECT * FROM passengers WHERE passport_number = 5773159633;

SELECT * FROM flights WHERE id = 36 AND year = 2023 AND month = 7;

SELECT * FROM airports WHERE id = 8 OR id = 4;

SELECT name, phone_number FROM passengers
JOIN people
ON people.passport_number = passengers.passport_number
WHERE passengers.flight_id = 36;

SELECT name, phone_number FROM people
JOIN phone_calls
ON phone_calls.receiver = people.phone_number
WHERE phone_calls.caller = '(367) 555-5533';

SELECT name, phone_number FROM people
JOIN phone_calls
ON phone_calls.caller = people.phone_number
WHERE phone_calls.receiver = '(367) 555-5533';

SELECT * FROM atm_transactions WHERE atm_location = 'Leggett Street';

SELECT people.name, COUNT(*) as count
FROM atm_transactions
JOIN bank_accounts
ON bank_accounts.account_number = atm_transactions.account_number
JOIN people
ON bank_accounts.person_id = people.id
WHERE atm_location = 'Leggett Street'
GROUP BY bank_accounts.account_number
ORDER BY count DESC;

SELECT * FROM phone_calls
JOIN people
ON receiver = phone_number
WHERE caller = '(367) 555-5533' or receiver = '(367) 555-5533'
AND year = 2023;

-- Robin has no passport?
