-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Aug 05, 2020 at 07:03 PM
-- Server version: 10.1.38-MariaDB
-- PHP Version: 7.3.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `used_books_store`
--

-- --------------------------------------------------------

--
-- Table structure for table `books`
--

CREATE TABLE `books` (
  `id` int(11) NOT NULL,
  `title` varchar(15) NOT NULL,
  `auther_name` text NOT NULL,
  `translator_name` varchar(15) NOT NULL,
  `release_name` varchar(15) NOT NULL,
  `release_year` int(11) NOT NULL,
  `pages_number` int(11) NOT NULL,
  `weight` int(11) NOT NULL,
  `condition` varchar(15) NOT NULL,
  `price` int(11) NOT NULL,
  `quantity_in_store` int(11) NOT NULL,
  `created_at` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `books`
--

INSERT INTO `books` (`id`, `title`, `auther_name`, `translator_name`, `release_name`, `release_year`, `pages_number`, `weight`, `condition`, `price`, `quantity_in_store`, `created_at`) VALUES
(1, 'book1', 'auther3', '', 'book1', 2020, 19, 200, 'new', 30, 5, '2020-07-06'),
(2, 'book1', 'auther4,aurther5', '', 'book2', 2020, 19, 200, 'old', 15, 4, '2020-07-05'),
(3, 'book2', 'author1,author2', '', 'book2', 1995, 50, 350, 'new', 45, 0, '2020-07-06'),
(4, 'book2', 'author1,author2', 'translator1', 'book2 arabic', 1995, 354, 350, 'good', 60, 0, '2020-07-03');

-- --------------------------------------------------------

--
-- Table structure for table `customers`
--

CREATE TABLE `customers` (
  `id` int(11) NOT NULL,
  `fname` varchar(11) NOT NULL,
  `lname` varchar(11) NOT NULL,
  `address` varchar(11) NOT NULL,
  `phone_number` varchar(15) NOT NULL,
  `created_at` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `customers`
--

INSERT INTO `customers` (`id`, `fname`, `lname`, `address`, `phone_number`, `created_at`) VALUES
(123, 'customer1', 'customer1', 'address1', '123456789', '2020-07-01'),
(456, 'customer2', 'customer2', 'address2', '234567891', '2020-07-02'),
(789, 'customer3', 'customer3', 'address3', '345678912', '2020-07-03');

-- --------------------------------------------------------

--
-- Table structure for table `deals`
--

CREATE TABLE `deals` (
  `id` int(11) NOT NULL,
  `s_date` date NOT NULL,
  `customer_id` int(11) NOT NULL,
  `purchase_type` varchar(15) NOT NULL,
  `employee_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `deals`
--

INSERT INTO `deals` (`id`, `s_date`, `customer_id`, `purchase_type`, `employee_id`) VALUES
(1, '2020-07-09', 123, 'credit card', 1111),
(2, '2016-07-16', 456, 'bit', 2222),
(3, '2020-06-21', 789, 'bank bass', 2222),
(4, '2020-07-08', 789, 'Bit', 2222);

-- --------------------------------------------------------

--
-- Table structure for table `deals_details`
--

CREATE TABLE `deals_details` (
  `id` int(11) NOT NULL,
  `book_id` int(11) NOT NULL,
  `deal_id` int(11) NOT NULL,
  `price` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `deals_details`
--

INSERT INTO `deals_details` (`id`, `book_id`, `deal_id`, `price`) VALUES
(1, 1, 1, 30),
(2, 2, 1, 15),
(3, 3, 2, 45),
(4, 4, 3, 60),
(5, 3, 4, 14),
(6, 4, 4, 60);

-- --------------------------------------------------------

--
-- Table structure for table `deliveries`
--

CREATE TABLE `deliveries` (
  `id` int(11) NOT NULL,
  `s_date` date NOT NULL,
  `address` text NOT NULL,
  `type` varchar(15) NOT NULL,
  `price` int(11) NOT NULL,
  `status` varchar(15) NOT NULL DEFAULT 'binding'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `deliveries`
--

INSERT INTO `deliveries` (`id`, `s_date`, `address`, `type`, `price`, `status`) VALUES
(1, '2020-07-21', 'address1', 'post', 16, 'binding'),
(2, '2020-07-21', 'address2', 'xpress', 46, 'binding'),
(3, '2020-07-09', 'address3', 'post express', 49, 'binding'),
(4, '2020-07-07', '', 'xpress', 30, 'binding');

-- --------------------------------------------------------

--
-- Table structure for table `deliveries_details`
--

CREATE TABLE `deliveries_details` (
  `id` int(11) NOT NULL,
  `deal_details_id` int(11) NOT NULL,
  `delivery_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `deliveries_details`
--

INSERT INTO `deliveries_details` (`id`, `deal_details_id`, `delivery_id`) VALUES
(1, 1, 1),
(2, 2, 2),
(3, 3, 3),
(4, 5, 4),
(5, 6, 4);

-- --------------------------------------------------------

--
-- Table structure for table `employees`
--

CREATE TABLE `employees` (
  `id` int(11) NOT NULL,
  `fname` varchar(11) NOT NULL,
  `lname` varchar(11) NOT NULL,
  `address` varchar(11) NOT NULL,
  `phone_number` varchar(11) NOT NULL,
  `s_date` date NOT NULL,
  `e_date` date DEFAULT NULL,
  `hour_price` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `employees`
--

INSERT INTO `employees` (`id`, `fname`, `lname`, `address`, `phone_number`, `s_date`, `e_date`, `hour_price`) VALUES
(1111, 'employee1', 'employee1', 'address1', '1122334455', '2020-07-08', NULL, 29),
(2222, 'employee2', 'employee2', 'address2', '2233445566', '2020-07-06', NULL, 34),
(3333, 'employee3', 'employee3', 'address3', '3344556677', '2020-07-03', '2020-07-22', 31);

-- --------------------------------------------------------

--
-- Table structure for table `expenses`
--

CREATE TABLE `expenses` (
  `id` int(11) NOT NULL,
  `month` int(11) NOT NULL,
  `year` int(11) NOT NULL,
  `rent` int(11) NOT NULL,
  `property_tax` int(11) NOT NULL,
  `water` int(11) NOT NULL,
  `electric` int(11) NOT NULL,
  `phone` int(11) NOT NULL,
  `cellular` int(11) NOT NULL,
  `salaries` int(11) NOT NULL,
  `e_delivery` int(11) NOT NULL,
  `p_delivery` int(11) NOT NULL,
  `others` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `orders`
--

CREATE TABLE `orders` (
  `id` int(11) NOT NULL,
  `book_id` int(11) NOT NULL,
  `customer_id` int(11) NOT NULL,
  `calling_date` date DEFAULT NULL,
  `created_at` date NOT NULL,
  `status` varchar(15) NOT NULL DEFAULT 'binding '
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `orders`
--

INSERT INTO `orders` (`id`, `book_id`, `customer_id`, `calling_date`, `created_at`, `status`) VALUES
(1, 1, 123, NULL, '2020-07-25', 'binding '),
(2, 4, 789, '2020-07-04', '2020-07-01', 'binding ');

-- --------------------------------------------------------

--
-- Table structure for table `purchase`
--

CREATE TABLE `purchase` (
  `id` int(11) NOT NULL,
  `book_id` int(11) NOT NULL,
  `quantity` int(11) NOT NULL,
  `price` int(11) NOT NULL,
  `p_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `purchase`
--

INSERT INTO `purchase` (`id`, `book_id`, `quantity`, `price`, `p_date`) VALUES
(1, 1, 20, 10, '2020-07-01'),
(2, 2, 15, 9, '2020-07-01'),
(3, 3, 12, 11, '2020-06-01'),
(4, 4, 16, 8, '2020-06-02');

-- --------------------------------------------------------

--
-- Table structure for table `working_hours`
--

CREATE TABLE `working_hours` (
  `id` int(11) NOT NULL,
  `worker_id` int(11) NOT NULL,
  `w_year` int(4) NOT NULL,
  `w_month` int(2) NOT NULL,
  `quantity` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `working_hours`
--

INSERT INTO `working_hours` (`id`, `worker_id`, `w_year`, `w_month`, `quantity`) VALUES
(1, 1111, 2020, 6, 135),
(2, 1111, 2020, 7, 122);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `books`
--
ALTER TABLE `books`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `customers`
--
ALTER TABLE `customers`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `deals`
--
ALTER TABLE `deals`
  ADD PRIMARY KEY (`id`),
  ADD KEY `customer_id` (`customer_id`),
  ADD KEY `employee_id` (`employee_id`);

--
-- Indexes for table `deals_details`
--
ALTER TABLE `deals_details`
  ADD PRIMARY KEY (`id`),
  ADD KEY `book_id` (`book_id`),
  ADD KEY `deal_id` (`deal_id`);

--
-- Indexes for table `deliveries`
--
ALTER TABLE `deliveries`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `deliveries_details`
--
ALTER TABLE `deliveries_details`
  ADD PRIMARY KEY (`id`),
  ADD KEY `delivery_id` (`delivery_id`),
  ADD KEY `deal_details_id` (`deal_details_id`);

--
-- Indexes for table `employees`
--
ALTER TABLE `employees`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`id`),
  ADD KEY `book_id` (`book_id`),
  ADD KEY `customer_id` (`customer_id`);

--
-- Indexes for table `purchase`
--
ALTER TABLE `purchase`
  ADD PRIMARY KEY (`id`),
  ADD KEY `book_id` (`book_id`);

--
-- Indexes for table `working_hours`
--
ALTER TABLE `working_hours`
  ADD PRIMARY KEY (`id`),
  ADD KEY `worker_id` (`worker_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `books`
--
ALTER TABLE `books`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `deals`
--
ALTER TABLE `deals`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `deals_details`
--
ALTER TABLE `deals_details`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `deliveries`
--
ALTER TABLE `deliveries`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `deliveries_details`
--
ALTER TABLE `deliveries_details`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `employees`
--
ALTER TABLE `employees`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3334;

--
-- AUTO_INCREMENT for table `orders`
--
ALTER TABLE `orders`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `purchase`
--
ALTER TABLE `purchase`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `working_hours`
--
ALTER TABLE `working_hours`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `deals`
--
ALTER TABLE `deals`
  ADD CONSTRAINT `deals_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customers` (`id`),
  ADD CONSTRAINT `deals_ibfk_2` FOREIGN KEY (`employee_id`) REFERENCES `employees` (`id`);

--
-- Constraints for table `deals_details`
--
ALTER TABLE `deals_details`
  ADD CONSTRAINT `deals_details_ibfk_1` FOREIGN KEY (`book_id`) REFERENCES `books` (`id`),
  ADD CONSTRAINT `deals_details_ibfk_2` FOREIGN KEY (`deal_id`) REFERENCES `deals` (`id`);

--
-- Constraints for table `deliveries_details`
--
ALTER TABLE `deliveries_details`
  ADD CONSTRAINT `deliveries_details_ibfk_2` FOREIGN KEY (`delivery_id`) REFERENCES `deliveries` (`id`),
  ADD CONSTRAINT `deliveries_details_ibfk_3` FOREIGN KEY (`deal_details_id`) REFERENCES `deals_details` (`id`);

--
-- Constraints for table `orders`
--
ALTER TABLE `orders`
  ADD CONSTRAINT `orders_ibfk_2` FOREIGN KEY (`book_id`) REFERENCES `books` (`id`),
  ADD CONSTRAINT `orders_ibfk_3` FOREIGN KEY (`customer_id`) REFERENCES `customers` (`id`);

--
-- Constraints for table `purchase`
--
ALTER TABLE `purchase`
  ADD CONSTRAINT `purchase_ibfk_1` FOREIGN KEY (`book_id`) REFERENCES `books` (`id`);

--
-- Constraints for table `working_hours`
--
ALTER TABLE `working_hours`
  ADD CONSTRAINT `working_hours_ibfk_1` FOREIGN KEY (`worker_id`) REFERENCES `employees` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
