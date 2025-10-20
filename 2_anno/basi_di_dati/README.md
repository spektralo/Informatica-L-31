# Basi di Dati
**Corso di Laurea Triennale in Informatica (L-31)**  
**Curriculum:** Cybersecurity e Digital Forensics  
**Docente:** Prof. Alaimo & Micale

**Studente:** Cristofero Paolo Viavattene  
**Università degli Studi di Catania**

---

## 📚 Contenuti del corso

### 🔹 Introduzione alle Basi di Dati
- Concetti fondamentali: basi di dati, modelli dei dati, architettura dei DBMS.  
- Differenze tra file system tradizionali e sistemi di gestione di basi di dati (DBMS).  

---

### 🔹 Il Modello dei Dati Relazionale
- Struttura del modello relazionale: relazioni, attributi, istanze, tuple.  
- Vincoli di integrità e concetto di chiave (primaria, esterna, candidata).  
- Algebra relazionale:  
  - **Operatori fondamentali:** selezione, proiezione, join, unione, differenza, prodotto cartesiano.  
  - **Operatori derivati:** divisione, intersezione, rinomina, ecc.

---

### 🔹 Il Linguaggio SQL (Structured Query Language)

#### Definizione dei dati (DDL)
- Creazione di tabelle, domini e indici.  
- Specifica di vincoli di integrità (PRIMARY KEY, FOREIGN KEY, UNIQUE, CHECK).  

#### Interrogazione dei dati (DQL)
- Operatori fondamentali: join, selezione, proiezione.  
- Operatori aggregati: `SUM`, `AVG`, `MIN`, `MAX`, `COUNT`.  
- Operatore di raggruppamento (`GROUP BY`) e clausola `HAVING`.  
- Interrogazioni nidificate e correlate.  
- Operatori insiemistici (`UNION`, `INTERSECT`, `EXCEPT`).  
- Query ricorsive con `WITH RECURSIVE`.  

#### Manipolazione dei dati (DML)
- Inserimento (`INSERT`), eliminazione (`DELETE`) e modifica (`UPDATE`) di tuple.  
- Definizione e gestione di **viste** (`CREATE VIEW`).  
- Vincoli di integrità generici e **trigger** per basi di dati attive.  
- Controllo degli accessi: `GRANT`, `REVOKE`.  

---

### 🔹 Progettazione delle Basi di Dati

- **Progettazione concettuale:** modellazione tramite diagrammi E-R (Entità-Relazioni).  
- **Progettazione logica:** traduzione del modello concettuale in schema relazionale.  
- **Progettazione fisica:** definizione di indici, ottimizzazione delle prestazioni e gestione dello storage.  

---

### 🔹 Normalizzazione delle Basi di Dati

- **Anomalie** di aggiornamento, inserimento e cancellazione.  
- **Dipendenze funzionali** e loro ruolo nella progettazione.  
- **Decomposizioni di schemi:**  
  - Che conservano i dati.  
  - Che conservano le dipendenze funzionali.  
- **Forme Normali:**  
  - Seconda Forma Normale (2NF)  
  - Terza Forma Normale (3NF)  
  - Forma Normale di Boyce–Codd (BCNF).  

---

### 🔹 Basi di Dati XML

- Struttura e rappresentazione dei dati XML.  
- Query su XML (XPath, XQuery).  
- Confronto tra modelli relazionali e XML.  

---

### 🔹 Introduzione ai Database NoSQL

- Caratteristiche e differenze rispetto ai database relazionali.  
- Modelli NoSQL principali:  
  - Document-oriented (MongoDB, CouchDB)  
  - Key-Value  
  - Column-oriented  
  - Graph-oriented  
- Vantaggi e limiti di scalabilità, consistenza e flessibilità.  

---

### 🔹 Sistemi e Tecnologie

- **Relazionali:** MySQL  
- **Interfacce e tecnologie web:** integrazione con PHP, JavaScript e Ajax.  
- **NoSQL:** CouchDB, MongoDB.  
ù




