-- phpMyAdmin SQL Dump
-- version 4.2.12deb2+deb8u2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Feb 15, 2018 at 09:31 AM
-- Server version: 5.5.55-0+deb8u1
-- PHP Version: 5.6.30-0+deb8u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `banc_test_eolienne`
--

-- --------------------------------------------------------

--
-- Table structure for table `eoliennes`
--

CREATE TABLE IF NOT EXISTS `eoliennes` (
`ID_eolienne` int(11) NOT NULL,
  `nom_eol` char(50) DEFAULT NULL,
  `modele` char(50) DEFAULT NULL,
  `types_eolienne` char(25) DEFAULT NULL,
  `fabricant` char(100) DEFAULT NULL,
  `pdf_datasheet` varchar(200) DEFAULT NULL,
  `supprimer` tinyint(1) NOT NULL DEFAULT '0'
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;


--
-- Table structure for table `releves`
--

CREATE TABLE IF NOT EXISTS `releves` (
`ID_releves` int(11) NOT NULL,
  `date_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `force_vent` float DEFAULT NULL,
  `puissance` float DEFAULT NULL,
  `consigne` int(11) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=1125 DEFAULT CHARSET=latin1;


-- --------------------------------------------------------

--
-- Table structure for table `scenarios`
--

CREATE TABLE IF NOT EXISTS `scenarios` (
`ID_scenarios` int(11) NOT NULL,
  `nom_scenar` char(25) DEFAULT NULL,
  `mode_vent` tinyint(1) DEFAULT NULL,
  `supprimer` tinyint(1) NOT NULL DEFAULT '0'
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;


-- --------------------------------------------------------

--
-- Table structure for table `sequences`
--

CREATE TABLE IF NOT EXISTS `sequences` (
`ID_sequences` int(11) NOT NULL,
  `consigne` int(11) DEFAULT NULL,
  `duree` int(11) DEFAULT NULL,
  `force_vent` float DEFAULT NULL,
  `ID_scenarios` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tests`
--

CREATE TABLE IF NOT EXISTS `tests` (
  `date_heure` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `reference` varchar(25) DEFAULT NULL,
  `ID_eolienne` int(11) NOT NULL,
  `ID_releves` int(11) NOT NULL,
  `ID_scenarios` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `eoliennes`
--
ALTER TABLE `eoliennes`
 ADD PRIMARY KEY (`ID_eolienne`);

--
-- Indexes for table `releves`
--
ALTER TABLE `releves`
 ADD PRIMARY KEY (`ID_releves`);

--
-- Indexes for table `scenarios`
--
ALTER TABLE `scenarios`
 ADD PRIMARY KEY (`ID_scenarios`);

--
-- Indexes for table `sequences`
--
ALTER TABLE `sequences`
 ADD PRIMARY KEY (`ID_sequences`), ADD KEY `FK_Sequences_ID_scenarios` (`ID_scenarios`);

--
-- Indexes for table `tests`
--
ALTER TABLE `tests`
 ADD PRIMARY KEY (`ID_eolienne`,`ID_releves`,`ID_scenarios`), ADD KEY `FK_Tests_ID_releves` (`ID_releves`), ADD KEY `FK_Tests_ID_scenarios` (`ID_scenarios`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `eoliennes`
--
ALTER TABLE `eoliennes`
MODIFY `ID_eolienne` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `releves`
--
ALTER TABLE `releves`
MODIFY `ID_releves` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=1125;
--
-- AUTO_INCREMENT for table `scenarios`
--
ALTER TABLE `scenarios`
MODIFY `ID_scenarios` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT for table `sequences`
--
ALTER TABLE `sequences`
MODIFY `ID_sequences` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=17;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `sequences`
--
ALTER TABLE `sequences`
ADD CONSTRAINT `FK_Sequences_ID_scenarios` FOREIGN KEY (`ID_scenarios`) REFERENCES `scenarios` (`ID_scenarios`);

--
-- Constraints for table `tests`
--
ALTER TABLE `tests`
ADD CONSTRAINT `FK_Tests_ID_eolienne` FOREIGN KEY (`ID_eolienne`) REFERENCES `eoliennes` (`ID_eolienne`),
ADD CONSTRAINT `FK_Tests_ID_releves` FOREIGN KEY (`ID_releves`) REFERENCES `releves` (`ID_releves`),
ADD CONSTRAINT `FK_Tests_ID_scenarios` FOREIGN KEY (`ID_scenarios`) REFERENCES `scenarios` (`ID_scenarios`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
