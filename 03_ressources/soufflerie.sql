-- phpMyAdmin SQL Dump
-- version 4.5.5.1
-- http://www.phpmyadmin.net
--
-- Client :  127.0.0.1
-- Généré le :  Mar 24 Avril 2018 à 14:44
-- Version du serveur :  5.7.11
-- Version de PHP :  5.6.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `soufflerie`
--

-- --------------------------------------------------------

--
-- Structure de la table `capteurs`
--

CREATE TABLE `capteurs` (
  `id` int(11) NOT NULL,
  `nom` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `direct`
--

CREATE TABLE `direct` (
  `id` int(11) NOT NULL,
  `puissance` int(11) NOT NULL,
  `vent` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `eolienne`
--

CREATE TABLE `eolienne` (
  `id` int(255) NOT NULL,
  `model` varchar(255) NOT NULL,
  `type` varchar(255) NOT NULL,
  `fabricant` varchar(255) NOT NULL,
  `chemin` varchar(255) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Contenu de la table `eolienne`
--

INSERT INTO `eolienne` (`id`, `model`, `type`, `fabricant`, `chemin`) VALUES
(4, 'Air Breeze', 'Verticale', 'Primus', 'H:/Projet/banc_de_test_eolienne/02_documentation/1_eolienne/Air_Primus_Manuel.pdf'),
(3, 'Le model', 'Le type', 'Le fabricant', 'C:/Conf_AV.txt');

-- --------------------------------------------------------

--
-- Structure de la table `etatcapteur`
--

CREATE TABLE `etatcapteur` (
  `id` int(11) NOT NULL,
  `fk_capteur` int(11) NOT NULL,
  `relevé` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `phase`
--

CREATE TABLE `phase` (
  `id` int(11) NOT NULL,
  `fk_scenario` int(11) NOT NULL,
  `temps` int(11) NOT NULL,
  `puissance` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `phase`
--

INSERT INTO `phase` (`id`, `fk_scenario`, `temps`, `puissance`) VALUES
(35, 20, 20, 20),
(36, 20, 20, 50),
(37, 20, 20, 90),
(38, 20, 20, 10),
(39, 20, 1, 1);

-- --------------------------------------------------------

--
-- Structure de la table `resultat`
--

CREATE TABLE `resultat` (
  `id` int(11) NOT NULL,
  `fk_scenario` int(11) NOT NULL,
  `fk_phase` int(11) NOT NULL,
  `puissance` int(11) NOT NULL,
  `vent` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `scenario`
--

CREATE TABLE `scenario` (
  `id` int(11) NOT NULL,
  `nom` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `scenario`
--

INSERT INTO `scenario` (`id`, `nom`) VALUES
(20, 'Scenario 1');

--
-- Index pour les tables exportées
--

--
-- Index pour la table `capteurs`
--
ALTER TABLE `capteurs`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `direct`
--
ALTER TABLE `direct`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `eolienne`
--
ALTER TABLE `eolienne`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `etatcapteur`
--
ALTER TABLE `etatcapteur`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_capteur_idx` (`fk_capteur`);

--
-- Index pour la table `phase`
--
ALTER TABLE `phase`
  ADD PRIMARY KEY (`id`),
  ADD KEY `test_idx` (`fk_scenario`);

--
-- Index pour la table `resultat`
--
ALTER TABLE `resultat`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_scenario_idx` (`fk_scenario`),
  ADD KEY `fk_phase_idx` (`fk_phase`);

--
-- Index pour la table `scenario`
--
ALTER TABLE `scenario`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `capteurs`
--
ALTER TABLE `capteurs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `eolienne`
--
ALTER TABLE `eolienne`
  MODIFY `id` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT pour la table `etatcapteur`
--
ALTER TABLE `etatcapteur`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `phase`
--
ALTER TABLE `phase`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=40;
--
-- AUTO_INCREMENT pour la table `resultat`
--
ALTER TABLE `resultat`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `scenario`
--
ALTER TABLE `scenario`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;
--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `etatcapteur`
--
ALTER TABLE `etatcapteur`
  ADD CONSTRAINT `fk_capteur` FOREIGN KEY (`fk_capteur`) REFERENCES `capteurs` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `phase`
--
ALTER TABLE `phase`
  ADD CONSTRAINT `fkk_scenario` FOREIGN KEY (`fk_scenario`) REFERENCES `scenario` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `resultat`
--
ALTER TABLE `resultat`
  ADD CONSTRAINT `fk_phase` FOREIGN KEY (`fk_phase`) REFERENCES `phase` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_scenario` FOREIGN KEY (`fk_scenario`) REFERENCES `scenario` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
