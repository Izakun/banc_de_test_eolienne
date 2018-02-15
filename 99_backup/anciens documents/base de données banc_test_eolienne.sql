-- phpMyAdmin SQL Dump
-- version 4.5.5.1
-- http://www.phpmyadmin.net
--
-- Client :  127.0.0.1
-- Généré le :  Mar 30 Mai 2017 à 11:44
-- Version du serveur :  5.7.11
-- Version de PHP :  5.6.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `banc_test_eolienne`
--

-- --------------------------------------------------------

--
-- Structure de la table `eoliennes`
--

CREATE TABLE `eoliennes` (
  `ID_eolienne` int(11) NOT NULL,
  `nom_eol` char(50) DEFAULT NULL,
  `modele` char(50) DEFAULT NULL,
  `types_eolienne` char(25) DEFAULT NULL,
  `fabricant` char(100) DEFAULT NULL,
  `pdf_datasheet` varchar(200) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `eoliennes`
--

INSERT INTO `eoliennes` (`ID_eolienne`, `nom_eol`, `modele`, `types_eolienne`, `fabricant`, `pdf_datasheet`) VALUES
(1, 'eol_1', 'air breeze', 'type c', 'bob le bricoleur', 'C://chemin/du/dossier/fichier'),
(2, 'eol_2', 'type B', 'air breeze', 'boby', 'c:/document/datasheet/doc.pdf'),
(3, 'oel_3', NULL, 'air breeze', 'simon', 'data3'),
(4, 'eol_4', NULL, 'air breeze', 'thibault', 'data_4'),
(5, 'eol_5', NULL, 'air breeze', 'gauth', 'data_5');

-- --------------------------------------------------------

--
-- Structure de la table `releves`
--

CREATE TABLE `releves` (
  `ID_releves` int(11) NOT NULL,
  `date_time` datetime DEFAULT NULL,
  `force_vent` float DEFAULT NULL,
  `puissance` float DEFAULT NULL,
  `consigne` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `releves`
--

INSERT INTO `releves` (`ID_releves`, `date_time`, `force_vent`, `puissance`, `consigne`) VALUES
(1, '2017-02-27 02:06:08', 85, 35, 60),
(2, '2017-02-28 06:20:21', 20, 25, 40),
(3, '2017-03-10 05:21:29', 35, 25, 10),
(5, '2017-02-02 09:34:45', 60, 58, 45),
(6, '2017-03-09 04:39:14', 3.4, 36.4, 25),
(7, '2017-03-07 05:29:23', 24, 75, 100),
(8, '2017-02-08 03:16:25', 60, 49, 54),
(9, '2017-02-09 18:52:14', 70, 12, 5),
(10, '2017-03-23 05:23:12', 36, 62, 15),
(11, '2017-03-22 15:21:29', 96.2, 1.2, 5),
(12, '2017-03-21 08:12:35', 21.5, 74.1, 30),
(13, '2017-03-20 14:25:12', 63.1, 12.3, 10),
(14, '2017-05-24 10:26:29', 47, 36.1, 35);

-- --------------------------------------------------------

--
-- Structure de la table `scenarios`
--

CREATE TABLE `scenarios` (
  `ID_scenarios` int(11) NOT NULL,
  `nom_scenar` char(25) DEFAULT NULL,
  `mode_vent` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `scenarios`
--

INSERT INTO `scenarios` (`ID_scenarios`, `nom_scenar`, `mode_vent`) VALUES
(0, 'mode instantané', 0),
(1, '1er test eolienne', 1),
(2, 'test_oel_2', 0),
(3, 'blublublu', 0);

-- --------------------------------------------------------

--
-- Structure de la table `sequences`
--

CREATE TABLE `sequences` (
  `ID_sequences` int(11) NOT NULL,
  `consigne` int(11) DEFAULT NULL,
  `duree` time DEFAULT NULL,
  `force_vent` float DEFAULT NULL,
  `ID_scenarios` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `sequences`
--

INSERT INTO `sequences` (`ID_sequences`, `consigne`, `duree`, `force_vent`, `ID_scenarios`) VALUES
(1, 10, '03:14:10', 15, 1),
(2, 30, '00:09:30', NULL, 2);

-- --------------------------------------------------------

--
-- Structure de la table `tests`
--

CREATE TABLE `tests` (
  `date_heure` datetime DEFAULT NULL,
  `reference` varchar(25) DEFAULT NULL,
  `ID_eolienne` int(11) NOT NULL,
  `ID_releves` int(11) NOT NULL,
  `ID_scenarios` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `tests`
--

INSERT INTO `tests` (`date_heure`, `reference`, `ID_eolienne`, `ID_releves`, `ID_scenarios`) VALUES
(NULL, '1', 1, 1, 2),
(NULL, '', 1, 2, 1),
('2017-05-10 07:41:30', '1', 1, 3, 0),
('2017-05-10 06:36:14', '1', 1, 5, 0),
('2017-05-23 13:57:39', '1', 1, 12, 0),
(NULL, '1', 2, 2, 2),
(NULL, '2', 2, 3, 2),
(NULL, NULL, 2, 7, 1),
('2017-05-09 04:27:35', '1', 2, 8, 0),
(NULL, NULL, 2, 8, 1),
(NULL, '2', 2, 9, 2),
(NULL, NULL, 2, 12, 2),
(NULL, NULL, 3, 1, 2),
(NULL, NULL, 3, 5, 2),
(NULL, NULL, 3, 7, 2),
(NULL, NULL, 3, 8, 2),
('2017-05-12 06:24:29', '1', 3, 9, 0),
(NULL, NULL, 3, 10, 1),
(NULL, NULL, 3, 12, 1),
(NULL, NULL, 3, 13, 2),
(NULL, NULL, 4, 3, 2),
(NULL, NULL, 4, 8, 1),
(NULL, NULL, 4, 8, 2),
(NULL, NULL, 4, 11, 1),
(NULL, NULL, 5, 6, 1),
('2017-05-11 08:33:00', '1', 5, 8, 0),
(NULL, NULL, 5, 8, 2),
(NULL, NULL, 5, 13, 1);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `eoliennes`
--
ALTER TABLE `eoliennes`
  ADD PRIMARY KEY (`ID_eolienne`);

--
-- Index pour la table `releves`
--
ALTER TABLE `releves`
  ADD PRIMARY KEY (`ID_releves`);

--
-- Index pour la table `scenarios`
--
ALTER TABLE `scenarios`
  ADD PRIMARY KEY (`ID_scenarios`);

--
-- Index pour la table `sequences`
--
ALTER TABLE `sequences`
  ADD PRIMARY KEY (`ID_sequences`),
  ADD KEY `FK_Sequences_ID_scenarios` (`ID_scenarios`);

--
-- Index pour la table `tests`
--
ALTER TABLE `tests`
  ADD PRIMARY KEY (`ID_eolienne`,`ID_releves`,`ID_scenarios`),
  ADD KEY `FK_Tests_ID_releves` (`ID_releves`),
  ADD KEY `FK_Tests_ID_scenarios` (`ID_scenarios`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `eoliennes`
--
ALTER TABLE `eoliennes`
  MODIFY `ID_eolienne` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT pour la table `releves`
--
ALTER TABLE `releves`
  MODIFY `ID_releves` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;
--
-- AUTO_INCREMENT pour la table `scenarios`
--
ALTER TABLE `scenarios`
  MODIFY `ID_scenarios` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT pour la table `sequences`
--
ALTER TABLE `sequences`
  MODIFY `ID_sequences` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `sequences`
--
ALTER TABLE `sequences`
  ADD CONSTRAINT `FK_Sequences_ID_scenarios` FOREIGN KEY (`ID_scenarios`) REFERENCES `scenarios` (`ID_scenarios`);

--
-- Contraintes pour la table `tests`
--
ALTER TABLE `tests`
  ADD CONSTRAINT `FK_Tests_ID_eolienne` FOREIGN KEY (`ID_eolienne`) REFERENCES `eoliennes` (`ID_eolienne`),
  ADD CONSTRAINT `FK_Tests_ID_releves` FOREIGN KEY (`ID_releves`) REFERENCES `releves` (`ID_releves`),
  ADD CONSTRAINT `FK_Tests_ID_scenarios` FOREIGN KEY (`ID_scenarios`) REFERENCES `scenarios` (`ID_scenarios`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
